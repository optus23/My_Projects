//using System.Collections;
//using System.Collections.Generic;
//using UnityEngine;

//public class FollowCursor : MonoBehaviour
//{
//    private TrailRenderer trail;


//    // Use this for initialization
//    void Start()
//    {
//        Cursor.visible = false;
//    }

//    // Update is called once per frame
//    void Update()
//    {
//        Vector2 pos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
//        transform.position = pos;
//        if (Input.GetKeyDown(KeyCode.Space))
//        {
//            trail.startColor = Color.red;
//            trail.endWidth = 3;
//        }
//    }
//}
