// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "pch.h"
#include "TestCommon.h"
#include <Rest/Schema/1_0/Interface.h>
#include <Rest/Schema/IRestClient.h>
#include "TestHandler.h"

std::shared_ptr<TestHandler> GetTestHandler(
    const web::http::status_code& statusCode, const utility::string_t& sampleResponseString, const utility::string_t& mimeType)
{
    return std::make_shared<TestHandler>([&sampleResponseString, &mimeType, &statusCode](web::http::http_request request) ->
        pplx::task<web::http::http_response>
        {
            web::http::http_response response;
            if (!sampleResponseString.empty())
            {
                response.set_body(web::json::value::parse(sampleResponseString));
            }

            response.headers().set_content_type(mimeType);
            response.set_status_code(statusCode);
            return pplx::task_from_result(response);
        });
}