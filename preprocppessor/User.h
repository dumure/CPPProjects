#pragma once

extern int GlobalValue;

struct User
{
    char* login;
    char* password;
    int age;
};

User* createUser();

void destroyUser(User*);

void showGlobalValue_();