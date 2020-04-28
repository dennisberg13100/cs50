SELECT name FROM people WHERE id IN (
    select person_id from directors where movie_id in (
        select movie_id from ratings where rating >= 9
    )
)
