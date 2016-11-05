using UnityEngine;
using System.Collections;

public class KeyboardMove : MonoBehaviour 
{

	public Transform myTransform;
	public Rigidbody myRigidBody;
	public KeyCode PlayerMoveLeft;
	public KeyCode PlayerMoveRight;
	public KeyCode PlayerJump;
	public float MovePower;
	public bool isAddforce;
	public float Friction;
	public float JumpPow;
	public bool ActiveJump;
	public  bool isJump;

	public float jumpUpTime=0.1f;
	public float nowJumpTime=0.0f;

	private Vector3 MoveSpd;
	
	// Use this for initialization
	void Start () 
	{
		MoveSpd=Vector3.zero;
	}
	
	// Update is called once per frame
	void Update () 
	{
		
	}
	
	void FixedUpdate()
	{
		float h = Input.GetAxisRaw("Horizontal");

		// Move the character
		myRigidBody.velocity = new Vector3(h*30, myRigidBody.velocity.y,myRigidBody.velocity.z);

		Jump();

		if(nowJumpTime<=0.0f)
		{
			if(!isGround())
			{
				// Move the character
				myRigidBody.velocity = new Vector3(myRigidBody.velocity.x, -50.0f,myRigidBody.velocity.z);
			}
		}

	}

	void Jump()
	{
		if(ActiveJump)
		{
			if(!isJump)
			{
				if(Input.GetKeyDown(PlayerJump))
				{
					isJump=true;
					nowJumpTime=0.0f;
				}
			}
			
			else
			{
				nowJumpTime+=Time.deltaTime;
				float jumpSpd=50.0f;
				if(nowJumpTime>=0.2f)
				{
					jumpSpd*=-1.0f;

					if(isGround())
					{
						nowJumpTime=-1.0f;
						isJump=false;
					}
				}

				// Move the character
				myRigidBody.velocity = new Vector3(myRigidBody.velocity.x, jumpSpd,myRigidBody.velocity.z);

			}
		}
	}

	bool isGround()
	{
		int mask = 1 << LayerMask.NameToLayer ("Ground"); // Groundというレイヤー名を持つオブジェクトのみを対象にする
		RaycastHit hit;
		bool a = Physics.SphereCast ( // マスクで指定した対象がヒットしたらtrueを返す
		                             myTransform.position , // 発射点
		                             0.4f, // 飛ばす球体の半径
		                             -Vector3.up, // 飛ばす方向
		                             out hit, // ヒットした対象が入る(hit.collider.gameObjectでゲームオブジェクトを取得できる)
		                             0.55f, // 射程
		                             mask); // 対象のレイヤーマスク

		return (a);
	}


}
