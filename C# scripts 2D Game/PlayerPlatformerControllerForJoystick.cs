using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerPlatformerControllerForJoystick : PhysicsObject
{
    public Joystick joystick;
    public float maxSpeed = 7;
    public float jumpTakeOffSpeed = 7;

    [Range(0.0f, 0.6f)]
    public float joystickHorizontalRunSensibility=0.04f;
    [Range(0.0f, 0.4f)]
    public float joystickHorizontalWalkSensibility = 0.2f;
    [Range(0.2f, 1f)]
    public float joystickVerticalJumpSensibility = 0.7f;
    [Range(0.2f, 1f)]
    public float joystickCrouchSensibility = 0.4f;

    private SpriteRenderer spriteRenderer;
    private Animator animator;
    //private bool crouch;
   // private bool walk;

    // Use this for initialization
    void Awake()
    {
        spriteRenderer = GetComponent<SpriteRenderer>();
        animator = GetComponent<Animator>();
    }

    protected override void ComputeVelocity()
    {
        Vector2 move = Vector2.zero;
        //joystick sensibility

        if (joystick.Horizontal >= joystickHorizontalRunSensibility || joystick.Horizontal <= -joystickHorizontalRunSensibility)
        {
            move.x = joystick.Horizontal;
           //walk = false;
        }
        //walk disabled
        /*
        else if (joystick.Horizontal >= joystickHorizontalWalkSensibility || joystick.Horizontal <= -joystickHorizontalWalkSensibility)
        {
            if (joystick.Horizontal < joystickHorizontalRunSensibility || joystick.Horizontal > -joystickHorizontalRunSensibility)
            {
                walk = true;
                move.x = joystick.Horizontal;
            }
            else
            {
               walk = false;
            }
        }
        */

        if (joystick.Vertical > joystickVerticalJumpSensibility && grounded == true)
        {
            velocity.y = jumpTakeOffSpeed;
        }
        else if (Input.GetButtonUp("Jump"))  // GetButtonUp to joystick.Horizontal???
        {
            if (velocity.y > 0)
            {
                velocity.y = velocity.y * 0.5f;
            }
        }
        //crouch disabled
        /*
        if (joystick.Vertical < -joystickVerticalCrouchSensibility)
        {
            crouch = true;
        }
        else
        {
            crouch = false;
        }
        */
        bool flipSprite = (spriteRenderer.flipX ? (move.x > 0.01f) : (move.x < 0.01f));

        if (flipSprite)
        {
            spriteRenderer.flipX = !spriteRenderer.flipX;
        }

        if (animator)
        {
            animator.SetBool("grounded", grounded);
            animator.SetFloat("velocityX", Mathf.Abs(velocity.x) / maxSpeed);
          //animator.SetBool("crouch", crouch);
          //animator.SetBool("IsAttacking", AttackButton.IsAttacking);
          //animator.SetBool("walk", walk);
        }
        targetVelocity = move * maxSpeed;
    }
}
