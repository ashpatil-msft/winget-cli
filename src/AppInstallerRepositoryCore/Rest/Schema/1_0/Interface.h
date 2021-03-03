// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "Rest/Schema/IRestClient.h"
#include "cpprest/json.h"
#include <vector>

namespace AppInstaller::Repository::Rest::Schema::V1_0
{
    // Interface to this schema version exposed through IRestClient.
    struct Interface : public IRestClient
    {
        IRestClient::SearchResult Search(const std::string& restApiUri, const SearchRequest& request) const override;
        std::optional<Manifest::Manifest> GetManifestByVersion(const std::string& restApiUri, const std::string& packageId, const std::string& version, const std::string& channel) const override;
    };
}
