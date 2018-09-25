using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControladorPersonaje : MonoBehaviour {

    public float fuerzaSalto = 100f;

    private bool enSuelo = true;
    public Transform comprobadorSuelo;
    float comprobadorRadio = 0.07f;
    public LayerMask mascaraSuelo;

    private bool dobleSalto = false;

    private Animator anim;

    private bool corriendo = false;
    public float velocidad = 1f;
    public float maxVelocidad = 5f;
    private Rigidbody2D rb2d;

    void Awake()
    {
        anim = GetComponent<Animator>();
    }

	// Use this for initialization
	void Start () {
        rb2d = GetComponent<Rigidbody2D>();
	}
    
    void FixedUpdate()
    {
        float acelerate = 7f;
        float h = Input.GetAxis("Horizontal");
        float limitedSpeed = Mathf.Clamp(rb2d.velocity.x, -maxVelocidad, maxVelocidad);
        rb2d.AddForce(Vector2.right * velocidad * h * acelerate);
        rb2d.velocity = new Vector2(limitedSpeed, rb2d.velocity.y);

        if (h > 0.5) transform.localScale = new Vector3(1f, 1f, 1f);
        if (h < -0.5) transform.localScale = new Vector3(-1f, 1f, 1f);



        if (corriendo)
        {
            rb2d.velocity = new Vector2(velocidad, rb2d.velocity.y);
        }
        anim.SetFloat("VelX", Mathf.Abs(rb2d.velocity.x));
        enSuelo = Physics2D.OverlapCircle(comprobadorSuelo.position, comprobadorRadio, mascaraSuelo);
        anim.SetBool("IsGrounded", enSuelo);
        if (enSuelo)
        {
            dobleSalto = false; 
        }
    }

    // Update is called once per frame
    void Update() {
        if (Input.GetMouseButtonDown(0))
        {
            if (corriendo)
            { //Hacemos que salte
                if (enSuelo || !dobleSalto)
                {
                    rb2d.velocity = new Vector2(rb2d.velocity.x, fuerzaSalto);
                    if (!dobleSalto && !enSuelo) dobleSalto = true;
                }
            }
            else
            {
                corriendo = true;
            }
        }
    }
}
