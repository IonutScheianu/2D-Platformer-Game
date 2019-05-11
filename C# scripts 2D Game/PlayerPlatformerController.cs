using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerPlatformerController : PhysicsObject {

    public float maxSpeed = 7;
    public float jumpTakeOffSpeed = 7;
    [Range(100,700)]
    public int enemyHitForceUp=600;
    /*
    [Range(50, 200)]
    public int enemyHitForceLeft=100;
    [Range(50, 200)]
    public int enemyHitForceRight=100;
    */

    private SpriteRenderer spriteRenderer;
    private Animator animator;
    private Rigidbody2D playerRigidBody;

    // Use this for initialization
    void Awake () 
    {
        spriteRenderer = GetComponent<SpriteRenderer> (); 
        animator = GetComponent<Animator> ();
        playerRigidBody = GetComponent<Rigidbody2D>();
    }

    protected override void ComputeVelocity()
    {
        if (HealthManager.isDead == false) //disable movement is the player is dead
        {
            Vector2 move = Vector2.zero;

            move.x = Input.GetAxis("Horizontal");

            if (Input.GetButtonDown("Jump") && grounded)
            {
                velocity.y = jumpTakeOffSpeed;
            }
            else if (Input.GetButtonUp("Jump"))
            {
                if (velocity.y > 0)
                {
                    velocity.y = velocity.y * 0.5f;
                }
            }

            bool flipSprite = (spriteRenderer.flipX ? (move.x > 0.01f) : (move.x < 0.01f));
            if (flipSprite)
            {
                spriteRenderer.flipX = !spriteRenderer.flipX;
            }

            animator.SetBool("grounded", grounded);
            animator.SetFloat("velocityX", Mathf.Abs(velocity.x) / maxSpeed);

            targetVelocity = move * maxSpeed;
        }
    }
    private void receiveHit()
    {
        //completely functional, but a little confusing for gameplay
        /*
        float directionChance = Random.value;
        if (directionChance < 0.5f)
        {
            playerRigidBody.AddForce(Vector2.up * enemyHitForceUp);
            playerRigidBody.AddForce(Vector2.left * enemyHitForceLeft);
        }
        else
        {
            playerRigidBody.AddForce(Vector2.up * enemyHitForceUp);
            playerRigidBody.AddForce(Vector2.right * enemyHitForceRight);
        }
        */
        playerRigidBody.AddForce(Vector2.up * enemyHitForceUp);
        animator.SetTrigger("hit");
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "spikes") // if player touch spikes
        {
            receiveHit(); //bounce
            GetComponent<HealthManager>().takeDamage(); // decrease health
        }
        if(collision.gameObject.tag == "sawHalf")
        {
            receiveHit(); //bounce
            GetComponent<HealthManager>().takeDamage(); // decrease health
        }
        if (collision.gameObject.tag == "finish")
        {
            MainMenu menu = gameObject.AddComponent<MainMenu>();
            menu.winner(); //winner menu
        }
    }
}