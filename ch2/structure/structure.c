typedef struct{
    enum{male,female} sex;
    union{
        int children;
        int bread;
    }u
}sex_type;

typedef struct{
    char name[10];
    int age;
    float salary;
    sex_type sex_info;
}human_being;

int main(void){
    human_being person1,person2;
    person1.sex_info.sex=female;
    person2.sex_info.u.bread=1;
}