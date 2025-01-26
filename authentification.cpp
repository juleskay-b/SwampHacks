//
// Created by Jules on 1/25/2025.
//

#include "authentification.h"
#include <iostream>
#include <cstdlib>  // for system commands to open the web browser
#include <thread>
#include "httplib.h"
#include <regex>


Authentification::Authentification() : authenticated(false), accessToken("") {}

void Authentification::startHttpListener() {
    httplib::Server svr;

    svr.Get("/callback", [&](const httplib::Request &req, httplib::Response &res) {
        std::string fragment = req.target;  // Capture the request URL fragment

        std::regex tokenRegex("access_token=([^&]*)");
        std::smatch match;

        if (std::regex_search(fragment, match, tokenRegex) && match.size() > 1) {
            accessToken = match[1].str();
            authenticated = true;
            res.set_content("Login successful. You can close this window.", "text/html");
            std::cout << "Successfully logged in! Access token: " << accessToken << std::endl;
        } else {
            res.set_content("Login failed. Try again.", "text/html");
            std::cout << "Login failed." << std::endl;
        }
        svr.stop();  // Stop the server once the token is captured
    });

    std::cout << "Waiting for authentication on http://localhost:3000/callback ..." << std::endl;
    svr.listen("localhost", 3000);
}

void Authentification::handleLogin() {
    std::string auth0Domain = "dev-rxz6u2tdaz4oq77t.us.auth0.com";
    std::string clientId = "tIvPZI4vczjGi7HMJIaiRq6a9Aw2PuVLl";
    std::string redirectUri = "http://localhost:3000/callback";

    std::string authUrl = "https://" + auth0Domain + "/authorize?"
                          "response_type=token&client_id=" + clientId +
                          "&redirect_uri=" + redirectUri + "&scope=openid profile email";

    // Start the HTTP listener in a separate thread
    std::thread serverThread(&Authentification::startHttpListener, this);
    serverThread.detach();

    // Open the Auth0 login page in the default web browser
#ifdef __APPLE__
    std::string command = "open \"" + authUrl + "\"";  // macOS
#elif _WIN32
    std::string command = "start " + authUrl;  // Windows
#else
    std::string command = "xdg-open \"" + authUrl + "\"";  // Linux
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