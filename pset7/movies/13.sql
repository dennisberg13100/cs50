SELECT DISTINCT name FROM people
JOIN stars
ON people.id = stars.person_id
WHERE stars.movie_id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon'))
AND people.name != 'Kevin Bacon'
ORDER BY people.name