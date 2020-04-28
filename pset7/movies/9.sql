SELECT name
FROM people
WHERE id IN (
    select person_id from stars join movies on stars.movie_id = movies.id where movies.year = 2004
) ORDER BY birth