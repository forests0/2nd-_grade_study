-- 코드를 입력하세요
SELECT * FROM (
    SELECT animal_ins.animal_id, animal_ins.animal_type, animal_ins.name
    FROM animal_ins INNER JOIN animal_outs
    ON animal_ins.animal_id = animal_outs.animal_id
    WHERE animal_ins.sex_upon_intake != animal_outs.sex_upon_outcome
    ORDER BY animal_id ASC
    )

--join을 할 때, 테이블에 별칭을 붙여줘 좀 더 짧게 쓸 수도 있음
