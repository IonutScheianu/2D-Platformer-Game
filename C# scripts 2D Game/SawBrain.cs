using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SawBrain : MonoBehaviour
{
    public bool debugMode=false;
    public GameObject leftEdgeDetector;
    public GameObject rightEdgeDetector;
    [Range(0.0f, 3f)]
    public float verticalLaserDistance = 0.5f;
    public float horizontalLaserDistance = 0.2f;

    public Rigidbody2D mainBody;
    public bool isPlayer;
    [Range(0.01f, 0.1f)]
    public float minDistanceForHorizontalHit = 0.05f;

    [Range(0.0f, 1f)]
    public float moveSpeed = 0.03f;
    public float latencyBetweenSwitches = 0.2f;
    private float movement;
    private bool isStopped;
    private bool isToTheRight;
    private float timer;

    // Start is called before the first frame update
    void Start()
    {
        mainBody = GetComponentInParent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        // DEBUG
        /*
        Debug.DrawRay(leftEdgeDetector.transform.position, Vector2.down, Color.red);
        Debug.DrawRay(rightEdgeDetector.transform.position, Vector2.down, Color.blue);
        Debug.DrawRay(rightEdgeDetector.transform.position, Vector2.right, Color.blue);
        Debug.DrawRay(leftEdgeDetector.transform.position, Vector2.left, Color.red);
        */

        if (isStopped == true)
        {
            movement = 0;
            timer += Time.deltaTime;
            if(timer>=latencyBetweenSwitches)
            {
                isStopped = false;
                timer = 0;
            }
        }
        else
        {
            if(isToTheRight==false)
            {
                movement = moveSpeed;
            }
            else
            {
                movement = -moveSpeed;
            }
        }

        mainBody.MovePosition(mainBody.position + Vector2.left * movement);

        RaycastHit2D hitVerticalLeft = Physics2D.Raycast(leftEdgeDetector.transform.position, Vector2.down, verticalLaserDistance);
        RaycastHit2D hitVericalRight = Physics2D.Raycast(rightEdgeDetector.transform.position, Vector2.down, verticalLaserDistance);
        RaycastHit2D hitHorizontalRight = Physics2D.Raycast(rightEdgeDetector.transform.position, Vector2.right, horizontalLaserDistance);
        RaycastHit2D hitHorizontalLeft = Physics2D.Raycast(leftEdgeDetector.transform.position, Vector2.left, verticalLaserDistance);
        float hitHorizontalLeftDistance = hitHorizontalLeft.distance;
        float hitHorizontalRightDistance = hitHorizontalRight.distance;


        if (isToTheRight == false)
        {
            if (hitVerticalLeft.collider == null || hitHorizontalLeft.collider!=null && hitHorizontalLeftDistance <= minDistanceForHorizontalHit)
            {
                isStopped = true;
                isToTheRight = true;
            }
        }
        if (isToTheRight == true)
        {
            if (hitVericalRight.collider == null || hitHorizontalRight.collider!=null && hitHorizontalRightDistance <= minDistanceForHorizontalHit)
            {
                isStopped = true;
                isToTheRight = false;
            }
        }
    }
}
