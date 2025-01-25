//
// Created by Jules on 1/25/2025.
//

#include "authentification.h"
#include <iostream>
#include <cstdlib>  // For system commands to open the web browser

Authentification::Authentification() : authenticated(false), accessToken("") {}

void Authentification::handleLogin() {
    std::string auth0Domain = "your-auth0-domain";   // Replace with your Auth0 domain
    std::string clientId = "your-client-id";         // Replace with your Auth0 client ID
    std::string redirectUri = "http://localhost:3000/callback";  // Redirect URL from your Auth0 settings

    std::string authUrl = "https://" + auth0Domain + "/authorize?"
                          "response_type=token&client_id=" + clientId +
                          "&redirect_uri=" + redirectUri + "&scope=openid profile email";

    // Open the URL in the default web browser
#ifdef _WIN32
    std::string command = "start " + authUrl;  // Windows
#else
    std::string command = "xdg-open \"" + authUrl + "\"";  // Linux/Mac
#endif

    system(command.c_str());

    // Simulated token input (In real applications, capture this securely)
    std::cout << "Login request sent. Enter your access token: ";
    std::cin >> accessToken;

    if (!accessToken.empty()) {
        authenticated = true;
        std::cout << "Successfully logged in!" << std::endl;
    } else {
        std::cout << "Login failed." << std::endl;
    }
}

bool Authentification::isAuthenticated() const {
    return authenticated;
}

std::string Authentification::getAccessToken() const {
    return accessToken;
}