// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "pch.h"
#include "RestSource.h"
#include <winget/ManifestYamlParser.h>

namespace AppInstaller::Repository::Rest
{
    using namespace Utility;
    namespace
    {
        // The base for the package objects.
        struct SourceReference
        {
            SourceReference(const std::shared_ptr<const RestSource>& source) :
                m_source(source) {}

        protected:
            std::shared_ptr<const RestSource> GetSource() const
            {
                std::shared_ptr<const RestSource> source = m_source.lock();
                THROW_HR_IF(E_NOT_VALID_STATE, !source);
                return source;
            }

        private:
            std::weak_ptr<const RestSource> m_source;
        };

        // The IPackage impl for RestSource.
        struct Package : public SourceReference, public IPackage
        {
            Package(const std::shared_ptr<const RestSource>& source, std::string idId) :
                SourceReference(source), m_idId(idId) {}

            // Inherited via IPackage
            std::shared_ptr<IPackageVersion> GetInstalledVersion() const override
            {
                // Although an index might be the backing store for installed packages, the installed package version
                // will be selected by external business logic.
                return {};
            }
            
        private:
            std::string m_idId;
        };
    }

    RestSource::RestSource(const SourceDetails& details, std::string identifier) :
        m_details(details), m_identifier(std::move(identifier))
    {
    }

    const SourceDetails& RestSource::GetDetails() const
    {
        return m_details;
    }

    const std::string& RestSource::GetIdentifier() const
    {
        return m_identifier;
    }

    SearchResult RestSource::Search(const SearchRequest& request) const
    {
        UNREFERENCED_PARAMETER(request);

        //  auto indexResults = m_index.Search(request);
        SearchResult result;
        std::shared_ptr<const RestSource> sharedThis = shared_from_this();

        // result.Matches.emplace_back(std::make_unique<Package>(sharedThis, "1"), std::move("Ashwini"));
        return {};
    }
}
