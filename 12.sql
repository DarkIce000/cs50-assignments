SELECT title FROM movies WHERE id IN(SELECT movie_id FROM stars Where person_id IN(SELECT id FROM people WHERE name = "Bradley Cooper" or name = "Jennifer Lawrence"));