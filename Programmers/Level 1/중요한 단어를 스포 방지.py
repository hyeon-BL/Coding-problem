def solution(message, spoiler_ranges):
    words = []
    
    import re
    for match in re.finditer(r'\S+', message):
        words.append({
            'word': match.group(),
            'start': match.start(),
            'end': match.end() - 1
        })

    secret_candidates = set()
    normal_occurrences = set()

    for w in words:
        is_spoiler = False
        for start, end in spoiler_ranges:
            if not (w['end'] < start or w['start'] > end):
                is_spoiler = True
                break
        
        if is_spoiler:
            secret_candidates.add(w['word'])
        else:
            normal_occurrences.add(w['word'])
    final_secrets = secret_candidates - normal_occurrences
    return len(final_secrets)

print(solution(	"my phone number is 01012345678 and may i have your phone number", [[5, 5], [25, 28], [34, 40], [53, 59]]))