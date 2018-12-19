// Code generated by schema.go; DO NOT EDIT.
// This file collects all the *.graphql schema files into a go file for
// easier use during runtime.
package schema

// String returns the GraphQL schema as a string
func String() string {
	return `type Album {
  id: ID!
  name: String!
}
type Artist {
  id: ID!
  name: String!
}
type Track {
  id: ID!
  name: String!
  album: Album!
  artists: [Artist!]!
  # Popularity of the track, it;s a number between 0 and 100
  popularity: Int!
}
type Playlist {
  id: ID!
  items: [Item]!
}

type Item {
  id: ID!
  addedAt: String!
  track: Track!
}
# Query type represents all the entry points to the API
type Query {
  # Get the content of a specific playlist given a spotify URL or URI
  playlsit(uri: String): Playlist!
}
`
}
