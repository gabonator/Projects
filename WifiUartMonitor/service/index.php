<?
  header("Access-Control-Allow-Origin: *");   
  header('Access-Control-Allow-Methods: POST, GET, OPTIONS');
  header('Access-Control-Allow-Headers: X-Requested-With, content-type');

  $channel = preg_replace("/[^A-Za-z0-9 ]/", '', $_SERVER["QUERY_STRING"]);
  $content = file_get_contents("php://input");

  file_put_contents("last_".$channel, $content);
  if ($content != "" && $content != "\n")
  {
    file_put_contents("data/".$channel."/".getCurrent(), $content, FILE_APPEND);
  }

  function getCurrent()
  {
    return date("Y-m-d").".txt";
  }

  function getTs()
  {
    return date("Y-m-d H:i:s");
  }
?>