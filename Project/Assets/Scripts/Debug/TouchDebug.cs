using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class TouchDebug : MonoBehaviour 
{
	public Text Began,Moved,Ended,Stationary,Canceled;

	void Awake()
	{
		Application.targetFrameRate = 60;
	}

	// Use this for initialization
	void Start () 
	{
		Began.enabled=false;
		Moved.enabled=false;
		Ended.enabled=false;
		Stationary.enabled=false;
		Canceled.enabled=false;
	}
	
	// Update is called once per frame
	void Update () 
	{
		if(Input.touchSupported)
		{

			if(Input.touchCount<=0)
			{
				Began.enabled=false;
				Moved.enabled=false;
				Ended.enabled=false;
				Stationary.enabled=false;
				Canceled.enabled=false;

				return;
			}

			Began.enabled=Input.touches[0].phase==TouchPhase.Began;
			Moved.enabled=Input.touches[0].phase==TouchPhase.Moved;
			Ended.enabled=Input.touches[0].phase==TouchPhase.Ended;
			Stationary.enabled=Input.touches[0].phase==TouchPhase.Stationary;
			Canceled.enabled=Input.touches[0].phase==TouchPhase.Canceled;
		}
	}
}
