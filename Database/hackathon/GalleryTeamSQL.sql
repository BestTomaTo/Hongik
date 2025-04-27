-- SQL 1
/*
SELECT aname, count(*) as Popularity
FROM a_likes
GROUP BY aname
*/

-- SQL 2
/*
SELECT Artists.aname AS Artist_Name,
       AVG(Artwork.price) AS Average_price
FROM   Artists, Artwork
WHERE  Artists.aName = Artwork.aName
GROUP BY Artists.aname
HAVING AVG(Artwork.price) = (
   SELECT MIN(Average_price)
   FROM (
       SELECT AVG(price) AS Average_price
       FROM Artwork, Artists
       WHERE Artists.aName = Artwork.aName
       GROUP BY Artists.aname
   )
);*/

-- SQL 3

SELECT classify.title, MAX(Artwork.price) AS max_price
FROM classify
JOIN Artwork ON classify.title = Artwork.title
GROUP BY classify.title
HAVING COUNT(classify.kinds_of_arts) >= 2
       AND MAX(Artwork.price) >= ALL(
             SELECT MAX(Artwork.price)
    		 FROM classify
    		 JOIN Artwork ON classify.title = Artwork.title
    		GROUP BY classify.title
    		HAVING COUNT(classify.kinds_of_arts) >= 2
			);