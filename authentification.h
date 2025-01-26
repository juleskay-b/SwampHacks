//
// Created by Jules on 1/25/2025.
//

#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include <string>


class Authentification {
public:
    Authentification();
    void handleLogin();
    bool isAuthenticated() const;
    std::string getAccessToken() const;

private:
    void startHttpListener();
    bool authenticated;
    std::string accessToken;
};

#endif //AUTHENTIFICATION_H
