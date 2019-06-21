#include "vectors.h"
#include "directional.h"
#include "shipcontrol.h"
#include "blackhole.h"
#include "stdio.h"
#include "stdint.h"

void blackHole(REF_P *ship_P, REF_P *ship_V){
    int r = 20; // Outer radius of black hole
    int r1 = 12; // Inner radius
    int r2 = 3; // Death zone

    REF_P hole;
    hole.x = 200; // x-coordinate
    hole.y = 40; // y-coordinate

    int32_t dx = (*ship_P).x - hole.x;
    int32_t dy = (*ship_P).y - hole.y;
    int32_t eval = dx*dx + dy*dy; // Distance from centrum

    int32_t vx = (hole.x - (*ship_P).x); // Distance from object to centrum on x-axis
    int32_t vy = (hole.y - (*ship_P).y); // Distance from object to centrum on y-axis

    int x = 16; // Scaling of x-direction
    int i = 3; // Scaling of y-dirrection in inner radius
    int o = 15; // Scaling of y-dirrection in outer radius

    if (r2 * r2 >= eval){ // Centrum
            (*ship_V).x = 0;
            (*ship_V).y = 0;
    } else if (r1 * r1 >= eval){ // Inner radius
            (*ship_V).x = (*ship_V).x + vx/x;
            (*ship_V).y = (*ship_V).y + vy/i;
    } else if (r*r >= eval){ // Outer radius
            (*ship_V).x = (*ship_V).x + vx/x;
            (*ship_V).y = (*ship_V).y + vy/o;
    }
}

//Use this to call above funktion
/*  initVector(&ship_V, 8, 0);
    initREF_P(&ship_P, 0, 55);
    spdVAL = shipUpdate(spdVAL, &ship_V, &ship_P);
    blackHole(&ship_P, &ship_V); */


/*
REF_P blackHole_projectile(REF_P projectile_P){
    uint8_t r;
    REF_P hole;
    hole.x;
    hole.y;

    if (power(r, 2) >= power(projectile_P.x - hole.x, 2) + power(projectile_P.y - hole.y, 2)){
            projectile_P.x + (hole.x - projectile_P.x);
            projectile_P.y + (hole.y - projectile_P.y);
    }
    return projectile_P;
}

*/



/*

#iknclude "blackHole.h"

void blackHole(uint8_t x, uint8_t y){
    int n0 = 0;
    int n2 = n0+2;
    int n4 = n0+4;
    int n6 = n0+6;
    int n8 = n0+8;
    int n10 = n0+10;
    int n12 = n0+12;
    int m0 = 0;
    int m2 = m0+2;
    int m4 = m0+4;
    int m6 = m0+6;
    int m8 = m0+8;
    int m10 = m0+10;
    int m12 = m0+12;
*/
    /*
    if(!(n0<x<n12 && m0<y<n12)){
        ();
    }
    */
/*
    if((n0 < x < n4) && (m0 < y < m4)){
        if((n0 < x < n2) && (m0 < y < m2)){
            ();
        } else if((n0<x<n2) && (m2<y<m4)){
            ();
        } else if((n2<x<n4) && (m0<y<m2)){
            ();
        } else if((n2<x<n4) && (m2<y<m4)){
            ();
        }
        }
    }

    if(n0<x<n4 && m4<y<m8){
        if(n0<x<n2 && m4<y<m6){
            ();
        } else if(n0<x<n2 && m6<y<m8){
            ();
        } else if(n2<x<n4 && m4<y<m6){
            ();
        } else if(n2<x<n4 && m6<y<m8){
            ();
        }
        }
    }

    if(n0<x<n4 && m8<y<m12){
        if(n0<x<n2 && m8<y<m10){
            ();
        } else if(n0<x<n2 && m10<y<m12){
            ();
        } else if(n2<x<n4 && m8<y<m10){
            ();
        } else if(n2<x<n4 && m10<y<m12){
            ();
        }
        }
    }

    if(n4<x<n8 && m0<y<m4){
        if(n4<x<n6 && m0<y<m2){
            ();
        } else if(n4<x<n6 && m2<y<m4){
            ();
        } else if(n6<x<n8 && m0<y<m2){
            ();
        } else if(n6<x<n8 && m2<y<m4){
            ();
        }
        }
    }

    if(n4<x<n8 && m8<y<m12){
        if(n4<x<n6 && m8<y<m10){
            ();
        } else if(n4<x<n6 && m10<y<m12){
            ();
        } else if(n6<x<n8 && m8<y<m10){
            ();
        } else if(n6<x<n8 && m10<y<m12){
            ();
        }
        }
    }

    if(n8<x<n12 && m0<y<m4){
        if(n8<x<n10 && m0<y<m2){
            ();
        } else if(n8<x<n10 && m2<y<m4){
            ();
        } else if(n10<x<n12 && m0<y<m2){
            ();
        } else if(n10<x<n12 && m2<y<m4){
            ();
        }
        }
    }

    if(n8<x<n12 && m4<y<m8){
        if(n8<x<n10 && m4<y<m6){
            ();
        } else if(n8<x<n10 && m6<y<m8){
            ();
        } else if(n10<x<n12 && m4<y<m6){
            ();
        } else if(n10<x<n12 && m6<y<m8){
            ();
        }
        }
    }

    if(n8<x<n12 && m8<y<m12){
        if(n8<x<n10 && m8<y<m10){
            ();
        } else if(n8<x<n10 && m10<y<m12){
            ();
        } else if(n10<x<n12 && m8<y<m10){
            ();
        } else if(n10<x<n12 && m10<y<m12){
            ();
        }
        }
    }

    if(n4<x<n8 && m4<y<m8){
        ();
    }
}
*/
