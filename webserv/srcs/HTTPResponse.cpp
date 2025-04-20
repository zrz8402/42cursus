#include "HTTPResponse.hpp"


HTTPResponse::HTTPResponse()
{

}

HTTPResponse::~HTTPResponse()
{

}


void HTTPResponse::set_status(t_status_code code)
{
    this->code = code;
}

void HTTPResponse::set_header(const std::string& name, const std::string& value)
{
    this->headers[name] = value;
}

void HTTPResponse::set_content_type(const std::string& type)
{
    this->set_header("Content-Type", type);
}

void HTTPResponse::set_body(const std::string& content)
{
    this->body = content;
    this->set_header("Content-Length", to_string(body.size()));
}


std::string HTTPResponse::get_header(const std::string& name) const
{
    std::map<std::string, std::string>::const_iterator it = this->headers.find(name);
    if (it == this->headers.end())
        return ("");
    return (it->second);
}


std::string HTTPResponse::serialize() const
{
    std::string response;

    response = "HTTP/1.1 " + to_string(this->code) + " " + get_message_from_status(this->code) + "\r\n";

    for (std::map<std::string, std::string>::const_iterator it = this->headers.begin(); it != this->headers.end(); ++it)
    {
        response += it->first + ": " + it->second + "\r\n";
    }

    response += "\r\n";

    response += body;

    return (response);
}


void HTTPResponse::clear()
{
    this->code = OK;
    this->headers.clear();
    this->body.clear();
}


std::string HTTPResponse::get_message_from_status(t_status_code code)
{   
    switch (code)
    {
        // 1xx Informational
        case CONTINUE: return "Continue";
        case SWITCHING_PROTOCOLS: return "Switching Protocols";

        // 2xx Success
        case OK: return "OK";
        case CREATED: return "Created";
        case ACCEPTED: return "Accepted";
        case NO_CONTENT: return "No Content";

        // 3xx Redirection
        case MOVED_PERMANENTLY: return "Moved Permanently";
        case FOUND: return "Found";
        case NOT_MODIFIED: return "Not Modified";

        // 4xx Client Errors
        case BAD_REQUEST: return "Bad Request";
        case UNAUTHORIZED: return "Unauthorized";
        case FORBIDDEN: return "Forbidden";
        case NOT_FOUND: return "Not Found";
        case METHOD_NOT_ALLOWED: return "Method Not Allowed";
        case REQUEST_TIMEOUT: return "Request Timeout";
        case CONFLICT: return "Conflict";
        case LENGTH_REQUIRED: return "Length Required";
        case TOO_LARGE: return "Payload Too Large";
        case TEAPOT: return "I'm a teapot";
        case TOO_MANY_REQUEST: return "Too Many Requests";

        // 5xx Server Errors
        case INTERNAL_SERVER_ERROR: return "Internal Server Error";
        case NOT_IMPLEMENTED: return "Not Implemented";
        case BAD_GATEWAY: return "Bad Gateway";
        case SERVICE_UNAVAILABLE: return "Service Unavailable";
        case GATEWAY_TIMEOUT: return "Gateway Timeout";

        default: return "Unknown Status";
    }
}

std::string HTTPResponse::get_mime_type(const std::string &file_extension) {

    std::map<std::string, std::string> mimes_types;

    mimes_types[".html"] = "text/html";
    mimes_types[".htm"] = "text/html";
    mimes_types[".css"] = "text/css";
    mimes_types[".js"] = "application/javascript";
    mimes_types[".json"] = "application/json";
    mimes_types[".png"] = "image/png";
    mimes_types[".jpg"] = "image/jpeg";
    mimes_types[".jpeg"] = "image/jpeg";
    mimes_types[".gif"] = "image/gif";
    mimes_types[".svg"] = "image/svg+xml";
    mimes_types[".ico"] = "image/x-icon";
    mimes_types[".xml"] = "application/xml";
    mimes_types[".pdf"] = "application/pdf";
    mimes_types[".txt"] = "text/plain";

    std::map<std::string, std::string>::iterator it = mimes_types.find(file_extension);

    if (it != mimes_types.end()) {
        return it->second;
    }

    return "application/octet-stream"

}
