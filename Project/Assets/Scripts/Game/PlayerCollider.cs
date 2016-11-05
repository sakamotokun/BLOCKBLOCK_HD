﻿//=========================================================
/// <summary>
/// プレイヤーのコントローラー
/// 2016/10/19 坂本友希
/// </summary>
//=========================================================
using UnityEngine;
using System.Collections;
//=========================================================
/// <summary>
/// プレイヤーのコントローラー
/// </summary>
//=========================================================
public class PlayerCollider : MonoBehaviour
{
	/// <summary>
	/// 自身のリジッドボディ
	/// </summary>
	public Rigidbody myRigidbody;

	//------------------------------------
	/// <summary>
	/// 初期化
	/// 2016/10/19 坂本友希
	/// </summary>
	//------------------------------------
	void Start ()
	{

	}
	
	//------------------------------------
	/// <summary>
	/// 更新
	/// 2016/10/19 坂本友希
	/// </summary>
	//------------------------------------
	void Update () 
	{

	}

	//------------------------------------
	/// <summary>
	/// 当たり判定のコルーチン
	/// 2016/10/19 坂本友希
	/// </summary>
	//------------------------------------
	void OnCollisionEnter(Collision other)
	{
		switch (other.gameObject.tag)
		{
		case "Ground":
			
			break;
		}
	}
}