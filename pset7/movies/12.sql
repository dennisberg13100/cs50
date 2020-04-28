SELECT title FROM movies WHERE id IN (
    select movie_id from stars where person_id = (
        select id from people where name = 'Johnny Depp'
    )
)
INTERSECT
SELECT title FROM movies WHERE id IN (
    select movie_id from stars where person_id = (
        select id from people where name = 'Helena Bonham Carter'
    )
)