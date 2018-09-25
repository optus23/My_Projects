using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour {

    public Transform player;
    public float softCam = 5f;

    Vector3 desface;

	// Use this for initialization
	void Start () {
        desface = transform.position - player.position;
	}
	void FixedUpdate()
    {
        Vector3 positionPlayer = player.position + desface;
        transform.position = Vector3.Lerp (transform.position, positionPlayer, softCam * Time.deltaTime);

      // Another Method --> transform.position = new Vector3 (player.position.x, player.position.y, transform.position.z);
    }
	// Update is called once per frame
	void Update () {
		
	}
}
