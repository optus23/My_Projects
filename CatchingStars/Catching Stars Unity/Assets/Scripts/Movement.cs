using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    private Rigidbody2D rb;
    
    private Vector2 moveInput;
    private Vector2 moveVelocity; // moveVelocity = moveInput * movSpeed
    public float movSpeed;

    private Vector2 rotationInput;
    public float angle;


    // Use this for initialization
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();

        angle = 0;
        
    }

    // Update is called once per frame
    void Update()
    {
        moveInput = new Vector2(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"));
        moveVelocity = moveInput.normalized * movSpeed;

        //rotationInput = new Vector2(Input.GetAxis("RHorizontal"), Input.GetAxis("RVertical"));
        //angle = Mathf.Rad2Deg * Mathf.Atan2(rotationInput.y, rotationInput.x);


    }

    void FixedUpdate()
    {
       
        rb.transform.Translate(moveVelocity * Time.fixedDeltaTime, Space.World);


        // rb.MovePosition(rb.position + moveVelocity * Time.fixedDeltaTime);

        //if (!float.IsNaN(angle))
        //    rb.MoveRotation(angle + 180);
    }
}
