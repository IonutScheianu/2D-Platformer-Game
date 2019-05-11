using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyGeneration : MonoBehaviour
{
    public GameObject sawHalf;
    //public GameObject slime; //to do

    [Range(0.0f, 1)]
    public float enemyRatio = 0.5f;

    public void placeEnemy(Vector2 coordinates)
    {
        float enemyChance = Random.value;
        if(enemyChance<enemyRatio)
        {
            Instantiate(sawHalf, new Vector3 (coordinates.x, coordinates.y + 1, -1), Quaternion.identity);
        }
        // to do
        /*
        else
        {
            Instantiate(slime, new Vector3(coordinates.x, coordinates.y + 1, -1), Quaternion.identity);
        }
        */
    }



}
