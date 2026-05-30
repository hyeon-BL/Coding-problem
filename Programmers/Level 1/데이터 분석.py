def solution(data, ext, val_ext, sort_by):
    answer = []
    indices = {"code": 0, "date": 1, "maximum": 2, "remain": 3}

    ext_idx = indices[ext]
    sort_idx = indices[sort_by]    
    for d in data:
        if d[ext_idx] < val_ext:
            answer.append(d)
    answer.sort(key=lambda x: x[sort_idx])
    return answer

print(solution([[1, 20300104, 100, 80], [2, 20300804, 847, 37], [3, 20300401, 10, 8]], 	"date", 20300501, "remain"))