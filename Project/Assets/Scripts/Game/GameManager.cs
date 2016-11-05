using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class GameManager : SingletonMonoBehaviour<GameManager>
{

	// Use this for initialization
	void Start () 
	{
		
	}
	
	// Update is called once per frame
	void Update () 
	{
		if(Input.GetKeyDown(KeyCode.M))
		{
			SceneManager.LoadScene("Game");
		}

		if(Input.GetKeyDown(KeyCode.Escape))
		{
			Application.Quit();
		}
	}
}
