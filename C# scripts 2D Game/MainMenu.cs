using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenu : MonoBehaviour
{

    public void playGame()
    {
        SceneManager.LoadScene("RandomMapGeneration");
    }

    public void quitGame()
    {
        Debug.Log("Quit!");
        Application.Quit();
    }

    public void gameOver()
    {
        SceneManager.LoadScene("GameOver");
    }
   
    public void winner()
    {
        SceneManager.LoadScene("Winner");
    }

}
