def list_ave(lst):
    if not lst:
        return 0
    return sum(lst) / len(lst)

if __name__ == "__main__":
    line = input("정수 리스트 입력 (공백으로 구분): ").strip()
    if not line:
        print("입력값이 비어 있습니다. 하나 이상의 정수를 입력하세요.")
        raise SystemExit(1)
    lst = list(map(int, line.split()))
    ave = list_ave(lst)
    print(f"리스트의 평균: {ave:.2f}")
