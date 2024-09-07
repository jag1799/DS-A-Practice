# AUTHOR: [jag1799]
# DATE: [2023,2024]

add_library(libdsa INTERFACE)

# Add common utiltiies across all groups
add_subdirectory(common)

# Add all data structures sources.
add_subdirectory(structures)