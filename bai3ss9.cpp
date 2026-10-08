#include <stdio.h>
#include <string.h>

struct FlightTicket {
    char pnrCode[15];
    char passengerName[50];
    char ticketClass[15];
    float baggageWeight;
    float baggageFee;
};

int main() {
    struct FlightTicket danhSachVe[100];
    int soLuong, i, j;
    char pnrInput[15];
    float tongTien = 0;
    int viTri = -1;

    printf("Nhap so luong ve may bay: ");
    scanf("%d", &soLuong);
    while (getchar() != '\n');

    for (i = 0; i < soLuong; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Ma ve PNR: ");
        fgets(danhSachVe[i].pnrCode, 15, stdin);
        danhSachVe[i].pnrCode[strcspn(danhSachVe[i].pnrCode, "\n")] = '\0';

        printf("Ho ten hanh khach: ");
        fgets(danhSachVe[i].passengerName, 50, stdin);
        danhSachVe[i].passengerName[strcspn(danhSachVe[i].passengerName, "\n")] = '\0';

        printf("Hang ve (Business/Deluxe/Eco): ");
        fgets(danhSachVe[i].ticketClass, 15, stdin);
        danhSachVe[i].ticketClass[strcspn(danhSachVe[i].ticketClass, "\n")] = '\0';

        do {
            printf("Khoi luong hanh ly ky gui (kg): ");
            scanf("%f", &danhSachVe[i].baggageWeight);

            if (danhSachVe[i].baggageWeight < 0) {
                printf("Khong hop le! Can nang phai >= 0.\n");
            }
        } while (danhSachVe[i].baggageWeight < 0);

        while (getchar() != '\n');

        if (strcmp(danhSachVe[i].ticketClass, "Business") == 0) {
            if (danhSachVe[i].baggageWeight <= 20) {
                danhSachVe[i].baggageFee = 0;
            } else {
                danhSachVe[i].baggageFee =
                    (danhSachVe[i].baggageWeight - 20) * 50000;
            }
        } else {
            danhSachVe[i].baggageFee =
                danhSachVe[i].baggageWeight * 50000;
        }
    }

    printf("\n================================== DANH SACH VE MAY BAY CHUYEN BAY ==================================\n");
    printf("%-5s %-12s %-25s %-12s %12s %15s\n",
           "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE",
           "HANH LY (KG)", "CUOC PHI (VNÐ)");
    printf("----------------------------------------------------------------------------------------------------\n");

    tongTien = 0;
    j = 0;

    for (i = 0; i < soLuong; i++) {
        printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
               i + 1,
               danhSachVe[i].pnrCode,
               danhSachVe[i].passengerName,
               danhSachVe[i].ticketClass,
               danhSachVe[i].baggageWeight,
               danhSachVe[i].baggageFee);

        tongTien += danhSachVe[i].baggageFee;

        if (danhSachVe[i].baggageWeight >
            danhSachVe[j].baggageWeight) {
            j = i;
        }
    }

    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Tong tien cuoc hanh ly toan chuyen: %.0f VNÐ\n", tongTien);
    printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n",
           danhSachVe[j].pnrCode,
           danhSachVe[j].passengerName,
           danhSachVe[j].baggageWeight);

    printf("\n--- CAP NHAT THONG TIN HANH LY ---\n");
    printf("Nhap ma ve PNR can cap nhat hanh ly: ");
    fgets(pnrInput, 15, stdin);
    pnrInput[strcspn(pnrInput, "\n")] = '\0';

    for (i = 0; i < soLuong; i++) {
        if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        printf("Khong tim thay ma ve PNR!\n");
    } else {
        printf("Nhap can nang hanh ly ky gui moi (kg): ");

        do {
            scanf("%f", &danhSachVe[viTri].baggageWeight);

            if (danhSachVe[viTri].baggageWeight < 0) {
                printf("Khong hop le! Can nang phai >= 0.\n");
            }
        } while (danhSachVe[viTri].baggageWeight < 0);

        while (getchar() != '\n');

        if (strcmp(danhSachVe[viTri].ticketClass, "Business") == 0) {
            if (danhSachVe[viTri].baggageWeight <= 20) {
                danhSachVe[viTri].baggageFee = 0;
            } else {
                danhSachVe[viTri].baggageFee =
                    (danhSachVe[viTri].baggageWeight - 20) * 50000;
            }
        } else {
            danhSachVe[viTri].baggageFee =
                danhSachVe[viTri].baggageWeight * 50000;
        }

        printf("Tim thay ma ve %s. Da cap nhat cuoc hanh ly moi: %.0f VNÐ.\n",
               danhSachVe[viTri].pnrCode,
               danhSachVe[viTri].baggageFee);
    }

    printf("\n================================ DANH SACH VE MAY BAY SAU CAP NHAT ================================\n");
    printf("%-5s %-12s %-25s %-12s %12s %15s\n",
           "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE",
           "HANH LY (KG)", "CUOC PHI (VNÐ)");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < soLuong; i++) {
        printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
               i + 1,
               danhSachVe[i].pnrCode,
               danhSachVe[i].passengerName,
               danhSachVe[i].ticketClass,
               danhSachVe[i].baggageWeight,
               danhSachVe[i].baggageFee);
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    return 0;
}
