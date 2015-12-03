#include "graphics.h"

// ################
// ## 6. LE MAIN ##
// ################
int main () {
    int n;
    BOOL b;

    init_graphics(600,600);

    write_text("Bonjour");
    write_text("Au revoir");
    write_text("àéèîôïç ÀÉÈÎÔÏÇ");

    n = 23;
    write_int(n);
    write_int(42);

    b = (2<3);
    write_bool(b);
    write_bool(2 == 3);

    POINT centre;
    centre = wait_clic();
    draw_fill_circle(centre, 20, rouge);

    wait_escape();
    exit (0);
}
