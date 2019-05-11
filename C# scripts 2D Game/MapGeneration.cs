using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MapGeneration : MonoBehaviour
{

    public GameObject groundTop;
    public GameObject groundMid;
    public GameObject bridge;
    public GameObject spikes;


    public int minPlatformSize = 1; //minimum size of a continuously platform
    public int maxPlatformSize = 10; //maximum size of a continuously platform
    public int minRandomPlatformSize = 1;
    public int maxRandomdPlatformSize = 3;
    public int maxPlatformHeight = 3;
    public int maxPlatformDrop = -3;
    public int maxGroundMidFill = 7;

    public int numberOfPlatforms = 100;

    [Range(0.0f, 1f)]
    public float randomChance = .5f;
    [Range(0.0f, 1f)]
    public float bridgeChance = .2f;
    [Range(0.0f, 1f)]
    public float spikesChance = .5f;
    [Range(0.0f, 1f)]
    public float coinChance = .5f;
    [Range(0.0f, 3f)]
    public float spikesDrop = .5f;
    [Range(0.0f, 1.0f)]
    public float enemyChance = .4f;
    [Range(1, 10)]
    public int minPlatformSizeSpawn = 3;

    private int currentNumberOfBlocks = 0;
    private int blockHeight;
    private bool isRandom = true;

    // Start is called before the first frame update
    void Start()
    {
       //begining tile
       // Instantiate(groundTop, new Vector2(0,0), Quaternion.identity);
       //++currentNumberOfBlocks;

        for(int platformIndex=0;platformIndex<numberOfPlatforms;++platformIndex)
        {
            if(platformIndex==numberOfPlatforms-10)
            {
                GetComponent<DecorationGeneration>().placeFinish(new Vector2(currentNumberOfBlocks, blockHeight+5));
            }
			//avoid 2 nearby empty platforms
            if(isRandom==true)
            {
                isRandom = false;
            }
            else
            {
                if(Random.value<randomChance)
                {
                    isRandom = true;
                }
                else
                {
                    isRandom = false;
                }
            }

            if (isRandom == true)
            {
                int randomPlatformSize = Mathf.RoundToInt(Random.Range(minRandomPlatformSize, maxRandomdPlatformSize));
                if (Random.value < spikesChance) //spike trap generation
                {
                    for (int tileIndex = 0; tileIndex < randomPlatformSize; ++tileIndex)
                    {
                        Instantiate(spikes, new Vector2(currentNumberOfBlocks, blockHeight-spikesDrop), Quaternion.identity); //currentNumberOfBlocks

                        for (int groundMidIndex = 1; groundMidIndex < maxGroundMidFill; ++groundMidIndex) // fill under top tile
                        {
                            Instantiate(groundMid, new Vector2(currentNumberOfBlocks, (blockHeight - groundMidIndex)-spikesDrop), Quaternion.identity);
                        }

                        ++currentNumberOfBlocks;
                    }
                }
                else //hole generation
                { 
                    //int randomPlatformSize = Mathf.RoundToInt(Random.Range(minRandomPlatformSize, maxRandomdPlatformSize));
                    currentNumberOfBlocks += randomPlatformSize;
                }
            }
            else
            {
                //bridge generation
                if(Random.value<bridgeChance)
                {
                    int bridgePlatformSize = Mathf.RoundToInt(Random.Range(minPlatformSize, maxPlatformSize));
                    blockHeight = blockHeight + Random.Range(maxPlatformDrop, maxPlatformHeight);

                    if(Random.value<coinChance)
                    {
                        int startTile = Mathf.RoundToInt(Random.Range(0, bridgePlatformSize));
                        GetComponent<DecorationGeneration>().placeCoin(new Vector2(currentNumberOfBlocks, blockHeight), Mathf.RoundToInt(Random.Range(1, bridgePlatformSize - startTile)), startTile);
                    }

                    for(int bridgeIndex=0; bridgeIndex< bridgePlatformSize; ++bridgeIndex)
                    {
                        if(bridgeIndex==0 || bridgeIndex== bridgePlatformSize - 1) //the bridge should have grass on left and right ends
                        {
                            Instantiate(groundTop, new Vector2(currentNumberOfBlocks, blockHeight), Quaternion.identity);

                            for(int groundMidIndex=1;groundMidIndex<maxGroundMidFill;++groundMidIndex) // fill under
                            {
                                Instantiate(groundMid, new Vector2(currentNumberOfBlocks, blockHeight-groundMidIndex), Quaternion.identity);
                            }
                            ++currentNumberOfBlocks;
                        }
                        else
                        {
                            Instantiate(bridge, new Vector2(currentNumberOfBlocks, blockHeight), Quaternion.identity);
                            ++currentNumberOfBlocks;
                        }
                    }

                }
                //paltform generation
                int platformSize = Mathf.RoundToInt(Random.Range(minPlatformSize, maxPlatformSize)); //continuously platform size
                blockHeight = blockHeight + Random.Range(maxPlatformDrop, maxPlatformHeight); // the next platform is accessible -> in some cases the player can`t jump at next tile hight

                if (Random.value < coinChance)
                {
                    int startTile = Mathf.RoundToInt(Random.Range(0, platformSize));
                    GetComponent<DecorationGeneration>().placeCoin(new Vector2(currentNumberOfBlocks, blockHeight), Mathf.RoundToInt(Random.Range(1, platformSize - startTile)), startTile);
                }

                if (platformSize>minPlatformSizeSpawn)
                {
                    if(Random.value<enemyChance)
                    {
                        GetComponent<EnemyGeneration>().placeEnemy(new Vector2(currentNumberOfBlocks, blockHeight));
                    }
                }
                
				//previous block + random
                //topGround generation
                for (int topGroundIndex = 0; topGroundIndex < platformSize; ++topGroundIndex)
                {
                    float decorationSpawnChance = Random.value;
                    Instantiate(groundTop, new Vector2(currentNumberOfBlocks, blockHeight), Quaternion.identity);

                    for (int groundMidIndex = 1; groundMidIndex < maxGroundMidFill; ++groundMidIndex) // fill
                    {
                        Instantiate(groundMid, new Vector2(currentNumberOfBlocks, blockHeight - groundMidIndex), Quaternion.identity);
                    }

                    //decoration generation
                    if(decorationSpawnChance<0.35)
                    {
                        GetComponent<DecorationGeneration>().PlaceObject(new Vector2(currentNumberOfBlocks, blockHeight), topGroundIndex);
                    }

                    ++currentNumberOfBlocks;
                }
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
