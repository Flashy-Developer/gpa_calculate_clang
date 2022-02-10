#include    "../includes/ohmylib.h"

int     main(void)
{
    t_user_data     testdata;

    //printf("%s,%s,%s,%s,%d\n", testdata.email, testdata.user_id, testdata.university_id, testdata.major_id, testdata.statement);
    printf("found email: %d\n", load_data("peakungg@gmail.com", "text.txt", &testdata));
    printf("%s,%s,%s,%s,%d\n", testdata.email, testdata.user_id, testdata.university_id, testdata.major_id, testdata.statement);
    return (0);
}