SELECT movies.title FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE movies.id IN (
    select movie_id from stars where person_id = (
        select id from people where name = "Chadwick Boseman"
    )
) ORDER BY ratings.rating DESC
LIMIT 5
