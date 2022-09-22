/*
 *  bmpServer.c
 *  Serve the image of the Mandelbrot Set.
 *
 *  Created by Alli Murray on 19/04/22.
 *  Server code created by Tim Lambert on 02/04/12.
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

#include "mandelbrot.h"

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 9216
#define NUMBER_OF_PAGES_TO_SERVE 10
// After serving this many pages the server will halt

int main(int argc, char *argv[]) {
    printf ("************************************\n");
    printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
    printf ("Serving bmps since 2012\n");

    int serverSocket = makeServerSocket (DEFAULT_PORT);
    printf ("Access this server at \
             http://localhost:%d/\n", DEFAULT_PORT);
    printf ("************************************\n");

    char request[REQUEST_BUFFER_SIZE];

    int numberServed = 0;
    while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
        printf("*** So far served %d pages ***\n", numberServed);

        int connectionSocket = waitForConnection (serverSocket);
        // Wait for a request to be sent from a web browser, open a
        // new connection for this conversation

        // Read the first line of the request sent by the browser
        int bytesRead;
        bytesRead = read(
            connectionSocket,
            request,
            (sizeof request) - 1
        );
        assert(bytesRead >= 0);
        // Were we able to read any data from the connection?

        // Print entire request to the console
        printf(" *** Received http request ***\n %s\n", request);

        double x;
        double y;
        int z;
        int success = sscanf(request, "GET /tile_x%lf_y%lf_z%d.bmp",
                             &x, &y, &z);
        if (!success || z < 0) {
            // Set default values for viewing the Mandelbrot Set
            x = 0;
            y = 0;
            z = 7;
        }

        // Send the browser a simple html page using http
        printf(" *** Sending http response ***\n");

        // Call the mandelbrot function to create the BMP and send it
        serveBMP(connectionSocket, x, y, z);

        // Close the connection after sending the page
        close(connectionSocket);

        numberServed++;
    }

    // Close the server connection after we are done
    printf("** shutting down the server **\n");
    close(serverSocket);

    return EXIT_SUCCESS;
}

// Start the server listening on the specified port number
int makeServerSocket(int portNumber) {
    // Create socket
    int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
    assert (serverSocket >= 0);
    // Error opening socket

    // Bind socket to listening port
    struct sockaddr_in serverAddress;
    memset ((char *) &serverAddress, 0,sizeof (serverAddress));

    serverAddress.sin_family      = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port        = htons (portNumber);

    // Let the server start immediately after a previous shutdown
    int optionValue = 1;
    setsockopt(
        serverSocket,
        SOL_SOCKET,
        SO_REUSEADDR,
        &optionValue,
        sizeof(int)
    );

    int bindSuccess =
        bind(
            serverSocket,
            (struct sockaddr *) &serverAddress,
            sizeof (serverAddress)
        );

    assert(bindSuccess >= 0);
    // If this assert fails wait a short while to let the operating
    // system clear the port before trying again

    return serverSocket;
}

// Wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection(int serverSocket) {
    // Listen for a connection
    const int serverMaxBacklog = 10;
    listen(serverSocket, serverMaxBacklog);

    // Accept the connection
    struct sockaddr_in clientAddress;
    socklen_t clientLen = sizeof (clientAddress);
    int connectionSocket =
        accept(
            serverSocket,
            (struct sockaddr *) &clientAddress,
            &clientLen
        );

    assert(connectionSocket >= 0);
    // Error on accept

    return (connectionSocket);
}
