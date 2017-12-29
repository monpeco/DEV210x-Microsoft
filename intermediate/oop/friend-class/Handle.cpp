#include "Handle.h"

Handle::Handle()
{
    body = new Body;  // Create the underlying "body" object.
}

Handle::~Handle()
{
    delete body;      // Delete the underlying "body" object.
}

void Handle::someOperationOnBody()
{
    body->someData = 42;    // Perform operations on the underlying "body" object.
}