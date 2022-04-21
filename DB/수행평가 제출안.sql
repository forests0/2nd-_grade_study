SELECT * FROM acc_intakes
WHERE name IS NOT NULL;

SELECT animal_id, breed FROM acc_intakes
WHERE breed LIKE '%Mix%';

SELECT animal_type, COUNT(*) FROM acc_intakes
GROUP BY animal_type;

SELECT animal_id FROM acc_intakes
WHERE animal_type = 'Cat' and intake_condition = 'Injured';

SELECT animal_type, MIN(datetime) FROM acc_intakes
GROUP BY animal_type;