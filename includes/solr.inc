<?php

/**
 * @file
 * Generate responses for the solr rest end point.
 */

/**
 * Responds to a SOLR GET request.
 *
 * @param array $parameters
 *   An associative array containing relevent data for this request.
 *   - path: The GET parameters from the URL path.
 *     - query: The SOLR query.
 *   - request: The request parameters passed onto SOLR.
 *     - See the SOLR documentation for more information.
 *
 * @return array
 *   The un-encoded response containing the generated SOLR results.
 */
function islandora_rest_solr_get_response(array $parameters) {
  $query = $parameters['path']['query'];
  $request = $parameters['request'];
  $solr = new IslandoraSolrQueryProcessor();
  $solr->buildAndExecuteQuery($query, $request);
  return $solr->islandoraSolrResult;
}
