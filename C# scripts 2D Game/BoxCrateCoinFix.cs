using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxCrateCoinFix : MonoBehaviour
{   
    //avoid coin behind a boxCrate
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag.Equals("boxCrate"))
        {
            Destroy(gameObject);
        }
    }
}
