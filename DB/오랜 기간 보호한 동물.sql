-- 코드를 입력하세요
SELECT *
FROM (
    SELECT animal_ins.name, animal_ins.datetime FROM animal_ins LEFT JOIN animal_outs
    ON animal_ins.animal_id = animal_outs.animal_id
    WHERE animal_outs.animal_id is null
    ORDER BY animal_ins.datetime ASC)
WHERE rownum < 4;

--rownum을 쓸 때, 정렬을 미리 해주려면 from 안에 부속질의문을 활용해서 써줘야함