using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DecorationGeneration : MonoBehaviour
{
    public GameObject boxCrate;
    public GameObject bush;
    public GameObject grass;
    public GameObject rock;
    public GameObject mushroomBrown;
    public GameObject mushroomRed;
    public GameObject signRight;
    public GameObject coin;
    public GameObject finish;

    public void PlaceObject(Vector2 coordinates, int tileIndex)
    {
        float decorationChance = Random.value;
        if(decorationChance<0.3f && tileIndex>0) //30% chance, do not spawn a crate box on first tile of a platform=>avoiding saw under box bug + too high to jump bug
        {
            Instantiate(boxCrate, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
        if (decorationChance >=0.3f && decorationChance<0.5f) //20%
        {
            Instantiate(bush, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
        if (decorationChance >= 0.5f && decorationChance < 0.6f) //10%
            {
            Instantiate(grass, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
        if (decorationChance >= 0.6f && decorationChance < 0.7f)//10%
        {
            Instantiate(rock, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
        if (decorationChance >= 0.7f && decorationChance < 0.8f)//10%
        {
            Instantiate(mushroomBrown, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
        if (decorationChance >= 0.8f && decorationChance < 0.9f)//10%
        {
            Instantiate(mushroomRed, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
        if (decorationChance >= 0.9f)//10%
        {
            Instantiate(signRight, new Vector3(coordinates.x, coordinates.y + 1, 1), Quaternion.identity);
        }
    }

    public void placeCoin(Vector2 coordinates, int amount, int startTile)
    {
        for(int coinInedx=0;coinInedx<amount;++coinInedx)
        {
            Instantiate(coin, new Vector3((coordinates.x + startTile) + coinInedx, coordinates.y + 1, -1), Quaternion.identity);
        }
    }

    public void placeFinish(Vector2 coordinates)
    {
        Instantiate(finish, new Vector3(coordinates.x, coordinates.y + 20, -1), Quaternion.identity);
    }

}
