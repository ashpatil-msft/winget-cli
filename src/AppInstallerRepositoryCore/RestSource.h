// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "Public/AppInstallerRepositorySource.h"
#include <AppInstallerSynchronization.h>
#include <memory>
#include <cpprest/http_client.h>

namespace AppInstaller::Repository::Rest
{
    using namespace web::http::client;

    // A source that holds a rest source.
    struct RestSource : public std::enable_shared_from_this<RestSource>, public ISource
    {
        RestSource(const SourceDetails& details, std::string identifier);

        RestSource(const RestSource&) = delete;
        RestSource& operator=(const RestSource&) = delete;

        RestSource(RestSource&&) = default;
        RestSource& operator=(RestSource&&) = default;

        ~RestSource() = default;

        // Get the source's details.
        const SourceDetails& GetDetails() const override;

        // Gets the source's identifier; a unique identifier independent of the name
        // that will not change between a remove/add or between additional adds.
        // Must be suitable for filesystem names.
        const std::string& GetIdentifier() const override;

        // Execute a search on the source.
        SearchResult Search(const SearchRequest& request) const override;

    private:
        SourceDetails m_details;
        std::string m_identifier;
    };
}
