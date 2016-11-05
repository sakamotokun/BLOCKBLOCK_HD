using UnityEngine;
using System.Collections;

public class TouchMove : MonoBehaviour 
{
//	public TRHolder myTr;
//	public bool isAddforce;
//	public bool ActiveJump;
//	public float MovePower;
//	public float Friction;
//	public float myGravity;
//	public float JumpPow;
//
//	private bool isCanJump;
//	private Vector3 MoveSpd;
//	private int JumpCnt;
//	public int MAX_JUMP_NUM=3;
//
//	//===========================================
//	// Initialize Once
//	//===========================================
//	void Start () 
//	{
//		JumpCnt=0;
//		isCanJump=false;
//		MoveSpd=Vector3.zero;
//	}
//
//	//===========================================
//	// Update called once per frame
//	//===========================================
//	void Update () 
//	{
//		Move ();
//
//		Jump();
//
//		if(!isGround())
//		{
//			MoveSpd.y=-myGravity;
//		}
//	}
//
//	//===========================================
//	// Update called once per one second
//	//===========================================
//	void FixedUpdate()
//	{
//		if(isAddforce)
//		{
//			myTr.rigidbody.AddForce(MoveSpd);
//		}
//
//		else
//		{
//			myTr.transform.Translate(MoveSpd);
//		}
//
//		MoveSpd*=Friction;
//	}
//
//	//===========================================
//	// Jump
//	//===========================================
//	void Jump()
//	{
//		if(ActiveJump)
//		{
//			if(isCanJump)
//			{
//				if(InputTouch.Instance.TouchPhase_(1)==TouchPhase.Began)
//				{
//					JumpCnt++;
//					if(JumpCnt>=MAX_JUMP_NUM)
//					{
//						isCanJump=false;
//					}
//					myTr.rigidbody.AddForce(Vector3.up*JumpPow);
//				}
//			}
//
//			else
//			{
//				if(isGround())
//				{
//					isCanJump=true;
//				}
//			}
//		}
//	}
//
//	//===========================================
//	// Move
//	//===========================================
//	void Move()
//	{
//		if(InputTouch.Instance.isTouch())
//		{
//			Vector2 ActiveTouchPosition=InputTouch.Instance.Position(InputTouch.Instance.CurrentActiveID_());
//			
//			if(ActiveTouchPosition.x<Screen.width/2.0f)
//			{
//				MoveSpd.x=-MovePower;
//			}
//			
//			else
//			{
//				MoveSpd.x=MovePower;
//			}
//		}
//	}
//
//	//===========================================
//	// check on ground
//	//===========================================
//	bool isGround()
//	{
//		int mask = 1 << LayerMask.NameToLayer ("Ground"); // Groundというレイヤー名を持つオブジェクトのみを対象にする
//		RaycastHit hit;
//		bool a = Physics.SphereCast ( // マスクで指定した対象がヒットしたらtrueを返す
//		                             myTr.transform.position , // 発射点
//		                             0.1f, // 飛ばす球体の半径
//		                             -Vector3.up, // 飛ばす方向
//		                             out hit, // ヒットした対象が入る(hit.collider.gameObjectでゲームオブジェクトを取得できる)
//		                             0.8f, // 射程
//		                             mask); // 対象のレイヤーマスク
//		
//		return (a);
//	}
}
