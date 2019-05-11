using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class HealthManager : MonoBehaviour
{

    public float currentHealth;
    private float maxHealth = 1;

    public Texture2D fullHeart;
    public Texture2D halfHeart;
    public Texture2D emptyHeart;
    private Texture2D heart;

    public Vector2 healthPosition;

    public static bool isDead;

    // Start is called before the first frame update
    void Start()
    {
        currentHealth = maxHealth;
        heart = fullHeart;
    }

    // Update is called once per frame
    void Update()
    {
        healthMonitor();
    }

    void healthMonitor()
    {
        if(currentHealth==maxHealth)
        {
            heart = fullHeart;
            isDead = false;
        }
        if(currentHealth==maxHealth-0.5f)
        {
            heart = halfHeart;
            isDead = false;
        }
        if(currentHealth<=0)
        {
            heart = emptyHeart;
            gameOver();
        }
    }

    private void OnGUI()
    {
        GUI.BeginGroup(new Rect(healthPosition.x, healthPosition.y, 50, 50));
        GUI.DrawTexture(new Rect(0, 0, 50, 50), heart, ScaleMode.ScaleToFit);
        GUI.EndGroup();
    }

    public void gameOver()
    {
        isDead = true;
        MainMenu menu = gameObject.AddComponent<MainMenu>();
        menu.gameOver();
    }

    public void takeDamage()
    {
        currentHealth -= 0.5f;
    }
}
