#include    "../includes/ohmylib.h"

int     main(void)
{
    t_user_data     testdata;

    reset_data(&testdata);
    remove_broken_data("text.txt");
    //printf("%s,%s,%s,%s,%d\n", testdata.email, testdata.user_id, testdata.university_id, testdata.major_id, testdata.statement);
    printf("found email: %d\n", find_data("peakungg@gmail.com", "text.txt", &testdata));
    printf("%s\t%s\t%s\t%s\t%d\n", testdata.email, testdata.user_id, testdata.university_id, testdata.major_id, testdata.statement);
    return (0);
}