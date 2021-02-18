// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "IRestClient.h"

namespace AppInstaller::Repository::Rest
{
	struct RestClient
	{
		RestClient(const std::string restApi);

		// The return type of Search
		using SearchResult = Rest::Schema::IRestClient::SearchResult;

		RestClient(const RestClient&) = delete;
		RestClient& operator=(const RestClient&) = delete;

		RestClient(RestClient&&) = default;
		RestClient& operator=(RestClient&&) = default;

		// Performs a search based on the given criteria.
		Schema::IRestClient::SearchResult Search(const SearchRequest& request) const;

		std::optional<std::string> GetManifestByVersion(const std::string& packageId, const std::string& version) const;

	private:
		std::string m_restApiUri;
		std::unique_ptr<Schema::IRestClient> m_interface;
	};
}