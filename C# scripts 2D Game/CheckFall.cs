using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckFall : MonoBehaviour
{
    [Range(0,300)]
    public int detectionPosition = 100;
    // Update is called once per frame
    void Update()
    {
        checkIsFallen();
    }

    public void checkIsFallen()
    {
        if (gameObject.transform.position.y < -detectionPosition) //if player is lower than this position, isn`t on platform anymore
        {
            GetComponent<HealthManager>().takeDamage();
        }
    }

}
