using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CoinCounter : MonoBehaviour
{
    Text score;
    public static int contor;
    // Start is called before the first frame update
    void Start()
    {
        contor = 0;
        score = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        score.text = contor.ToString();
    }
}
