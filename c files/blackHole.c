
#include "blackhole.h"

void blackHole_ship(REF_P *P){
    int r = 34;
    REF_P hole;
    hole.x = 40;
    hole.y = 30;

    if (power(r, 2) >= power(ship_P.x - hole.x, 2) + power(ship_P.y - hole.y, 2)){
            ship_P.x + (hole.x - ship_P.x);
            ship_P.y + (hole.y - ship_P.y);
    }
}

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
