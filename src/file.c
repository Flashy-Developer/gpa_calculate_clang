#include	"../includes/ohmylib.h"

void print_file(t_student_data *stu_data)
{
	FILE *fp_add_grade;
	fp_add_grade=fopen("add_grade.txt","a+");
	fprintf(fp_add_grade,"%s",stu_data->student_id);
	fprintf(fp_add_grade,",");
	for(size_t i = 0; i < 10; i++)
	{
		if(*stu_data->subject[i])
		{
			fprintf(fp_add_grade,"%s",stu_data->subject[i]);
			fprintf(fp_add_grade,":");
			fprintf(fp_add_grade,"%.6f",stu_data->grade[i]);
			fprintf(fp_add_grade,":");
			fprintf(fp_add_grade,"%.6f",stu_data->credit[i]);
		}
		else
			fprintf(fp_add_grade,"-:-:-");
		if (i < 9)
			fprintf(fp_add_grade,",");
	}
	fprintf(fp_add_grade,"\n");
    fclose(fp_add_grade);
}
